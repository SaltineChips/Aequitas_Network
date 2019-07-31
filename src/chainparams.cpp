// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"
// TODO: Verify the requirement of below link
// #include "base58.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xaa;
        pchMessageStart[1] = 0xae;
        pchMessageStart[2] = 0xa1;
        pchMessageStart[3] = 0x42;
        vAlertPubKey = ParseHex("04e22531e96c9056be6b659c91a94fae445b5d517698712acdbef262f1ea321f85d131a669df3be611393f454852a2d08c6314bba5ca3cbe5616262da3d4a6efac");
        nDefaultPort = 90777;
        nRPCPort = 91777;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Californian Biohacker Faces DCA Investigation Over CRISPR Injection | JP Buntinx | May 17, 2019";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = 1 * COIN;
        vout[0].SetEmpty();
        CTransaction txNew(1, timeGenesisBlock, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = timeGenesisBlock; // Sat, December 15, 2018 8:00:00 PM
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = nNonceMain;

        /** Genesis Block MainNet */
        /*
        Hashed MainNet Genesis Block Output
        block.hashMerkleRoot == 7a5fd9fc575ec5ebee9e2d9ece344ffb75e5bfe0917bbc91ba260cfa1db094e1
        block.nTime = 1558180800
        block.nNonce = 49778
        block.GetHash = 0000c552112fe0a5ee2997139e791bf2fa9c15ced39385ed5756d7ca43531b62
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == nGenesisBlock);
        assert(genesis.hashMerkleRoot == nGenesisMerkle);

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,33);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,58);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,48);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        //vSeeds.push_back(CDNSSeedData("node1",  ""));
        //vSeeds.push_back(CDNSSeedData("node2",  ""));
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 9;
        strMNenginePoolDummyAddress = "AVFWdWihxT5JSdabScHquzB35FEMKXXg7q";
        strDevOpsAddress = "AVARxhnynrP3F6YLQCEXWLwxdNsKtuHEKe";
        nEndPoWBlock = 0x7fffffff;
        nStartPoSBlock = 0;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xbb;
        pchMessageStart[1] = 0xab;
        pchMessageStart[2] = 0x33;
        pchMessageStart[3] = 0xce;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 14);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 18);
        vAlertPubKey = ParseHex("0e376531e96c9056be6b659c91a94aeb24eb5d5257f139876af26ababae2f81f85d131a669df3be611393f454852a2d08c6314bba5ca3cbe5616262db3d4a6efac");
        nDefaultPort = 90776;
        nRPCPort = 91776;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime  = timeTestNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = nNonceTest;

        /** Genesis Block TestNet */
        /*
        Hashed TestNet Genesis Block Output
        block.hashMerkleRoot == 7a5fd9fc575ec5ebee9e2d9ece344ffb75e5bfe0917bbc91ba260cfa1db094e1
        block.nTime = 1558180830
        block.nNonce = 13265
        block.GetHash = 00018de7c1401239894e433c3bae0141a3bb320aa6ed88cd6601f9004b971a4d
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == hashTestNetGenesisBlock);

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,24);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,34);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,57);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,47);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xac;
        pchMessageStart[1] = 0x12;
        pchMessageStart[2] = 0x19;
        pchMessageStart[3] = 0x9e;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = timeRegNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 91775;
        strDataDir = "regtest";

        /** Genesis Block RegNet */
        /*
        Hashed RegNet Genesis Block Output
        block.hashMerkleRoot == 7a5fd9fc575ec5ebee9e2d9ece344ffb75e5bfe0917bbc91ba260cfa1db094e1
        block.nTime = 1558180890
        block.nNonce = 8
        block.GetHash = d13d22b700db8b54f0dee3960949fffc8a6ef2475d50e96888656ab5fe440269
        */

        assert(hashGenesisBlock == hashRegNetGenesisBlock);

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
