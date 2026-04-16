/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> nwk_join_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_join_indication(nwk_join_ind_t *ind)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uStack_28;
  apsme_update_device_req_t ud_req;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 != 0) {
    memset(&uStack_28,0,0x18);
    iVar1 = aps_secur_is_centralized();
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)nwk_get_extended_address();
    }
    else {
      puVar2 = (undefined4 *)aps_secur_get_tc_address();
    }
    uStack_28 = *puVar2;
    ud_req.field_0._0_4_ = puVar2[1];
    ud_req.field_0._4_4_ = *(undefined4 *)&(ind->extended_address).field_0;
    ud_req.device_address.field_0.u64._0_4_ =
         *(undefined4 *)((int)&(ind->extended_address).field_0 + 4);
    ud_req.device_address.field_0.u64._4_2_ = ind->network_address;
    if (ind->join_method < 6) {
      uVar3 = 1 << (ind->join_method & 0x1f);
      if ((uVar3 & 0x24) == 0) {
        if ((uVar3 & 0x12) == 0) {
          if ((uVar3 & 9) != 0) {
            ud_req.device_address.field_0.u8[6] = '\x01';
          }
        }
        else {
          ud_req.device_address.field_0.u8[6] = '\x03';
        }
      }
      else {
        ud_req.device_address.field_0.u8[6] = '\0';
      }
    }
    iVar1 = apsme_update_device_request(&uStack_28);
    if (iVar1 != 0) {
      log_write(2,"zdo_app_tc.c",0x10000,iVar1);
    }
  }
  return;
}

