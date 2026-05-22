/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  int error;
  undefined1 auStack_1c [4];
  mac_associate_rsp_t rsp;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) != 0) {
    rsp.device_address.field_0.u64._4_4_ = 0xfffe;
    auStack_1c = *(undefined1 (*) [4])&(ind->device_address).field_0;
    rsp.device_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(ind->device_address).field_0 + 4);
    mVar2 = nwk_accept_child(iface_id,&ind->device_address,ind->capability,'\0',
                             (ezb_shortaddr_t *)(rsp.device_address.field_0.u8 + 4));
    rsp.device_address.field_0.u8[6] = mVar2;
    if ((CONCAT31(extraout_var_00,mVar2) != 0xe2) &&
       (error = nwk_mm_asso_response(CONCAT31(in_register_00002029,iface_id),auStack_1c), error != 0
       )) {
      nwk_accept_child_done(error,(ezb_extaddr_t *)auStack_1c,'\0');
    }
  }
  return;
}

