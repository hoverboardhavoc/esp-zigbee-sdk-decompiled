/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_network_status_local
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_status_local(nwk_network_status_cmd_t *status_cmd)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_18 [4];
  nwk_nlme_event_ind_t ind;
  
  uVar2 = (uint)status_cmd->status_code;
  if (uVar2 == 0xd) {
    nwk_address_conflict_resolve(status_cmd->target_addr);
    return;
  }
  if (uVar2 < 0xe) {
    if (uVar2 == 0xb) {
      nwk_route_record_table_remove_by_dst(status_cmd->target_addr);
    }
    else if (uVar2 == 0xc) {
      nwk_concentrator_discovery();
    }
    else {
      if (uVar2 < 3) {
        nwk_route_table_remove_by_dst(status_cmd->target_addr);
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
  auStack_18 = (undefined1  [4])((uint)status_cmd->status_code << 0x10);
  ind.field_1._0_2_ = 0;
  ind._0_2_ = status_cmd->target_addr;
  nwk_nlme_event_indication((nwk_nlme_event_ind_t *)auStack_18);
  return;
}

