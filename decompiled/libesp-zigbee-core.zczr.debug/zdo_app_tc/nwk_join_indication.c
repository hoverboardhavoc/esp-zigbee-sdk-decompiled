/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> nwk_join_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_join_indication(nwk_join_ind_t *ind)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uStack_28;
  apsme_update_device_req_t ud_req;
  
  iVar4 = zdo_dev_joined();
  if (iVar4 != 0) {
    uStack_28 = 0;
    ud_req.field_0._0_4_ = 0;
    ud_req.field_0._4_4_ = 0;
    ud_req.device_address.field_0.u64._0_4_ = 0;
    ud_req.device_address.field_0.u64._4_4_ = 0;
    ud_req.device_shortaddr = 0;
    ud_req.status = '\0';
    ud_req._19_1_ = 0;
    iVar4 = aps_secur_is_centralized();
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)nwk_get_extended_address();
      uStack_28 = *puVar5;
      ud_req.field_0._0_4_ = puVar5[1];
    }
    else {
      puVar5 = (undefined4 *)aps_secur_get_tc_address();
      uStack_28 = *puVar5;
      ud_req.field_0._0_4_ = puVar5[1];
    }
    uVar2 = ud_req.device_address.field_0.u64._4_4_;
    ud_req.field_0._4_4_ = *(undefined4 *)&(ind->extended_address).field_0;
    ud_req.device_address.field_0.u64._0_4_ =
         *(undefined4 *)((int)&(ind->extended_address).field_0 + 4);
    uVar1 = ind->network_address;
    ud_req.device_address.field_0.u64._4_2_ = uVar1;
    uVar3 = ud_req.device_address.field_0.u64._4_4_;
    if (ind->join_method < 6) {
      uVar6 = 1 << (ind->join_method & 0x1f);
      ud_req.device_address.field_0.u8[7] = SUB41(uVar2,3);
      if ((uVar6 & 0x24) == 0) {
        if ((uVar6 & 0x12) == 0) {
          if ((uVar6 & 9) != 0) {
            ud_req.device_address.field_0.u8[6] = 1;
            uVar3 = ud_req.device_address.field_0.u64._4_4_;
          }
        }
        else {
          ud_req.device_address.field_0.u8[6] = 3;
          uVar3 = ud_req.device_address.field_0.u64._4_4_;
        }
      }
      else {
        ud_req.device_address.field_0.u8[6] = 0;
        uVar3 = ud_req.device_address.field_0.u64._4_4_;
      }
    }
    ud_req.device_address.field_0.u64._4_4_ = uVar3;
    iVar4 = apsme_update_device_request(&uStack_28);
    if (iVar4 != 0) {
      log_write(2,"zdo_app_tc.c","UpdateDevice failed(0x%x)",iVar4);
    }
  }
  return;
}

