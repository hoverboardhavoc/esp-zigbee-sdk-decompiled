/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_network_status_local
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_status_local(nwk_network_status_cmd_t *status_cmd)

{
  nwk_network_status_cmd_t *pnVar1;
  uint uVar2;
  undefined1 auStack_18 [4];
  nwk_nlme_event_ind_t ind;
  
  uVar2 = (uint)status_cmd->status_code;
  if (uVar2 == 0xc) {
    nwk_concentrator_discovery();
  }
  else {
    if (uVar2 < 0xd) {
      if (uVar2 == 9) goto _L0;
      pnVar1 = status_cmd;
      if (9 < uVar2) goto _L0;
      if (uVar2 < 3) {
        nwk_route_table_remove_by_dst(status_cmd->target_addr);
        return;
      }
    }
    else {
      if (uVar2 == 0x13) {
        return;
      }
      if (uVar2 < 0x14) {
        if (uVar2 == 0xd) {
          nwk_address_conflict_resolve(status_cmd->target_addr);
          return;
        }
        uVar2 = uVar2 - 0xf & 0xff;
        if (uVar2 < 2) goto _L0;
      }
      else if (uVar2 == 0x14) goto _L0;
    }
    do {
      pnVar1 = (nwk_network_status_cmd_t *)__assert_func(0,0,0,0);
_L0:
    } while (uVar2 != 0xb);
    nwk_route_record_table_remove_by_dst
              (CONCAT11(*(undefined1 *)((int)&status_cmd->target_addr + 1),(char)pnVar1->target_addr
                       ));
  }
_L0:
  auStack_18 = (undefined1  [4])((uint)status_cmd->status_code << 0x10);
  ind.field_1._0_2_ = 0;
  ind._0_2_ = status_cmd->target_addr;
  nwk_nlme_event_indication((nwk_nlme_event_ind_t *)auStack_18);
  return;
}

