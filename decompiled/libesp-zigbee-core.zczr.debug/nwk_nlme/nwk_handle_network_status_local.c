/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  undefined1 auStack_18 [4];
  nwk_nlme_event_ind_t ind;
  
  bVar1 = status_cmd->status_code;
  if (bVar1 != 0xc) {
    if (bVar1 < 0xd) {
      if (bVar1 == 9) goto _L0;
      if (bVar1 < 10) {
        if (bVar1 < 3) {
          nwk_route_table_remove_by_dst(status_cmd->target_addr);
          return;
        }
      }
      else if (bVar1 == 0xb) {
        nwk_route_record_table_remove_by_dst(status_cmd->target_addr);
        goto _L0;
      }
    }
    else {
      if (bVar1 == 0x13) {
        return;
      }
      if (bVar1 < 0x14) {
        if (bVar1 == 0xd) {
          nwk_address_conflict_resolve(status_cmd->target_addr);
          return;
        }
        if ((0xc < bVar1) && ((byte)(bVar1 - 0xf) < 2)) goto _L0;
      }
      else if (bVar1 == 0x14) goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb2,
                  "nwk_handle_network_status_local",&_LC18);
  }
  nwk_concentrator_discovery();
_L0:
  auStack_18 = (undefined1  [4])((uint)status_cmd->status_code << 0x10);
  ind.field_1._0_2_ = 0;
  ind._0_2_ = status_cmd->target_addr;
  nwk_nlme_event_indication((nwk_nlme_event_ind_t *)auStack_18);
  return;
}

