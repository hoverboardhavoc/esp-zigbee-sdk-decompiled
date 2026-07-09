/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_network_status_local
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_status_local(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iStack_18;
  uint uStack_14;
  
  uVar2 = (uint)*param_1;
  if (uVar2 == 0xd) {
    nwk_address_conflict_resolve(*(undefined2 *)(param_1 + 1));
    return;
  }
  if (uVar2 < 0xe) {
    if (uVar2 == 0xb) {
      nwk_route_record_table_remove_by_dst(*(undefined2 *)(param_1 + 1));
    }
    else if (uVar2 == 0xc) {
      nwk_concentrator_discovery();
    }
    else {
      if (uVar2 < 3) {
        nwk_route_table_remove_by_dst(*(undefined2 *)(param_1 + 1));
        return;
      }
      uVar1 = 9;
      while (uVar2 != uVar1) {
_L0:
        __assert_func(0,0,0,0);
_L0:
        uVar1 = 0x14;
      }
    }
  }
  else {
    if (uVar2 == 0x13) {
      return;
    }
    if (0x13 < uVar2) goto _L0;
    uVar2 = uVar2 - 0xf & 0xff;
    if (1 < uVar2) goto _L0;
    ds_save_common_data();
  }
  iStack_18 = (uint)*param_1 << 0x10;
  uStack_14 = (uint)*(ushort *)(param_1 + 1);
  nwk_nlme_event_indication(&iStack_18);
  return;
}

