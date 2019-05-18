// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The CryptoCoderz Team / INSaNe project
// Copyright (c) 2018-2019 The Rubix project
// Copyright (c) 2018-2019 The Aequitas project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_MINING_H
#define BITCOIN_MINING_H

#include "bignum.h"

/** Minimum nCoinAge required to stake PoS */
static const unsigned int nStakeMinAge = 7 * (24 * 60); // One (1) Week
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 2 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Reserve block subsidy */
static const int64_t nBlockRewardReserve = 1000000 * COIN; // 4.7619047619% Reserved for Development ~One (1)million
/** Standard block subsidy */
static const int64_t nBlockStandardReward = 10 * COIN;
/** Superblock block subsidy */
static const int64_t nBlockSuperReward = 50 * COIN;
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = 60;
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = 30;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 90;
/** Desired block times/spacing */
static const int64_t GetTargetSpacing = BLOCK_SPACING;
/** MNengine collateral */
static const int64_t MNengine_COLLATERAL = (1 * COIN);
/** MNengine pool values */
static const int64_t MNengine_POOL_MAX = (999 * COIN);
/** MasterNode required collateral */
inline int64_t MasternodeCollateral(int nHeight) { return 1000; } // 1K AEQL required as collateral
/** Coinbase transaction outputs can only be staked after this number of new blocks (network rule) */
static const int nStakeMinConfirmations = 25;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 15; // 15-TXs | 90-Mined


#endif // BITCOIN_MINING_H
