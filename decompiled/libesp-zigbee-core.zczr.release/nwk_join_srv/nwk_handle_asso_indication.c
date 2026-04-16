/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_asso_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_asso_indication(uint8_t iface_id,mac_associate_ind_t *ind)

{
  _Bool _Var1;
  mac_status_t mVar2;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uStack_1c;
  mac_associate_rsp_t rsp;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) != 0) {
    rsp.device_address.field_0.u64._4_4_ = 0xfffe;
    uStack_1c = *(undefined4 *)&(ind->device_address).field_0;
    rsp.device_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(ind->device_address).field_0 + 4);
    mVar2 = nwk_accept_child(iface_id,&ind->device_address,ind->capability,'\0',
                             (ezb_shortaddr_t *)(rsp.device_address.field_0.u8 + 4));
    rsp.device_address.field_0.u8[6] = mVar2;
    if (CONCAT31(extraout_var_00,mVar2) != 0xe2) {
      nwk_mm_asso_response(CONCAT31(in_register_00002029,iface_id),&uStack_1c);
    }
  }
  return;
}

