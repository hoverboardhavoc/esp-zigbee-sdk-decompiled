/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time_ticker.o -> time_ticker_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void time_ticker_handle_timer(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = random_add_jitter(0x3e3,10);
  iVar2 = milli_timer_get_fire_time(&s_tmtk);
  milli_timer_fire_at(&s_tmtk,iVar1 + iVar2);
  fence();
  fence();
  if (((uint)s_tmtk.tm.next & 1) != 0) {
    nwk_fwd_handle_tick();
  }
  fence();
  fence();
  if (((uint)s_tmtk.tm.next & 2) != 0) {
    nwk_router_handle_tick();
  }
  fence();
  fence();
  if (((uint)s_tmtk.tm.next & 4) != 0) {
    nwk_concentrator_handle_tick();
  }
  fence();
  fence();
  if (((uint)s_tmtk.tm.next & 8) != 0) {
    aps_secur_handle_tick();
  }
  fence();
  fence();
  if (((uint)s_tmtk.tm.next & 0x10) != 0) {
    aps_dup_table_handle_tick();
  }
  return;
}

