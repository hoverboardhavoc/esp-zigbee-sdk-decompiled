/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_network_status_local
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_status_local(nwk_network_status_cmd_t *status_cmd)

{
  byte bVar1;
  nwk_network_status_cmd_t *pnVar2;
  undefined1 auStack_18 [4];
  nwk_nlme_event_ind_t ind;
  
  bVar1 = status_cmd->status_code;
  if (bVar1 == 0xd) {
    nwk_address_conflict_resolve(status_cmd->target_addr);
    return;
  }
  if (bVar1 < 0xe) {
    pnVar2 = status_cmd;
    if (bVar1 != 0xb) {
      if (bVar1 < 0xc) {
        if (bVar1 < 3) {
          nwk_route_table_remove_by_dst(status_cmd->target_addr);
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
    pnVar2 = (nwk_network_status_cmd_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb8,
                           "nwk_handle_network_status_local",&_LC18);
  }
  nwk_route_record_table_remove_by_dst
            (CONCAT11(*(undefined1 *)((int)&status_cmd->target_addr + 1),(char)pnVar2->target_addr))
  ;
_L0:
  auStack_18 = (undefined1  [4])((uint)status_cmd->status_code << 0x10);
  ind.field_1._0_2_ = 0;
  ind._0_2_ = status_cmd->target_addr;
  nwk_nlme_event_indication((nwk_nlme_event_ind_t *)auStack_18);
  return;
}

