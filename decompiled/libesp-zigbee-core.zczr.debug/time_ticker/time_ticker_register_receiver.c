/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time_ticker.o -> time_ticker_register_receiver
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void time_ticker_register_receiver(time_ticker_receiver_t receiver)

{
  int iVar1;
  undefined4 uVar2;
  
  test_and_set_bit(receiver,(bitfield_t *)&s_tmtk);
  iVar1 = milli_timer_is_running(&s_tmtk);
  if (iVar1 == 0) {
    uVar2 = random_noncrypto_range_u32(0x3e9);
    milli_timer_start(&s_tmtk,uVar2);
  }
  return;
}

