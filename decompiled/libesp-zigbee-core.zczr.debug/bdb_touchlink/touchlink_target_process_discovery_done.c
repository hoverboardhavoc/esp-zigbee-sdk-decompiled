/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_target_process_discovery_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_target_process_discovery_done(ezb_err_t error)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    if (error == 0) {
      pcVar2 = (char *)touchlink_commissioning_get();
      if (*pcVar2 == '\x04') goto _L0;
      if (*pcVar2 == '\x06') {
        iVar1 = touchlink_transaction_get();
        touchlink_zdo_set_rejoin_network_info((touchlink_event_rejoin_network_t *)(iVar1 + 0x610));
        return;
      }
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                    0xda,"touchlink_target_process_discovery_done",&_LC3);
    }
    touchlink_commissioning_task_result(1);
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0xcf,"touchlink_target_process_discovery_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_TARGET");
_L0:
    iVar1 = touchlink_transaction_get();
    touchlink_zdo_target_start_network_response((touchlink_event_start_network_t *)(iVar1 + 0x610));
  }
  return;
}

