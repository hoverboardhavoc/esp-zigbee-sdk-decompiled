/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_network_status_local
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_status_local(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iStack_18;
  uint uStack_14;
  
  bVar1 = *param_1;
  if (bVar1 == 0xd) {
    nwk_address_conflict_resolve(*(undefined2 *)(param_1 + 1));
    return;
  }
  if (bVar1 < 0xe) {
    pbVar2 = param_1;
    if (bVar1 != 0xb) {
      if (bVar1 < 0xc) {
        if (bVar1 < 3) {
          nwk_route_table_remove_by_dst(*(undefined2 *)(param_1 + 1));
          return;
        }
        if (bVar1 == 9) goto _L0;
      }
      else if (bVar1 == 0xc) {
        nwk_concentrator_discovery();
        goto _L0;
      }
      goto _L0;
    }
  }
  else {
    if (bVar1 == 0x13) {
      return;
    }
    if (bVar1 < 0x14) {
      if ((byte)(bVar1 - 0xf) < 2) {
        ds_save_common_data();
        goto _L0;
      }
    }
    else if (bVar1 == 0x14) goto _L0;
_L0:
    pbVar2 = (byte *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb8,
                                   "nwk_handle_network_status_local",&_LC18);
  }
  nwk_route_record_table_remove_by_dst(CONCAT11(param_1[2],pbVar2[1]));
_L0:
  iStack_18 = (uint)*param_1 << 0x10;
  uStack_14 = (uint)*(ushort *)(param_1 + 1);
  nwk_nlme_event_indication(&iStack_18);
  return;
}

