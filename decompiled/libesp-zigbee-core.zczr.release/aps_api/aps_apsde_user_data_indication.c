/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> aps_apsde_user_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_apsde_user_data_indication(aps_apsde_data_ind_t *ind)

{
  ezb_shortaddr_t eVar1;
  ushort uVar2;
  ezb_apsde_data_indication_callback_t p_Var3;
  int iVar4;
  _Bool _Var5;
  uint8_t *puVar6;
  undefined3 extraout_var;
  int iVar7;
  zmsg_t *pzVar8;
  ezb_apsde_data_ind_t eStack_48;
  
  if (ind != (aps_apsde_data_ind_t *)0x0) goto _L0;
  while( true ) {
    ind = (aps_apsde_data_ind_t *)__assert_func(0,0,0,0);
_L0:
    if (s_apsde_data_ind_handler == (ezb_apsde_data_indication_callback_t)0x0) goto _L0;
    pzVar8 = ind->asdu;
    iVar4 = zmsg_get_length(pzVar8);
    puVar6 = (uint8_t *)mm_alloc_notrap(1,iVar4);
    if ((puVar6 == (uint8_t *)0x0) && (iVar4 != 0)) break;
    iVar7 = zmsg_read_bytes(pzVar8,0,iVar4,puVar6);
    if (iVar7 == iVar4) {
_L0:
      p_Var3 = s_apsde_data_ind_handler;
      memset(&eStack_48,0,0x28);
      eStack_48.dst_address.u.short_addr = (ind->addr_info).grp_addr;
      eVar1 = (ind->addr_info).dst_addr;
      if (eStack_48.dst_address.u.short_addr == 0) {
        eStack_48.dst_address.addr_mode = '\x02';
        eStack_48.dst_address.u.short_addr = eVar1;
      }
      else {
        eStack_48.dst_address.addr_mode = '\x01';
        eStack_48.dst_address.u.group_addr.bcast = eVar1;
      }
      eStack_48.src_address.addr_mode = '\x02';
      eStack_48.src_address.u.short_addr = (ind->addr_info).src_addr;
      eStack_48.asdu_length = (uint16_t)iVar4;
      uVar2._0_1_ = (ind->addr_info).src_ep;
      uVar2._1_1_ = (ind->addr_info).dst_ep;
      eStack_48._20_2_ = uVar2 << 8 | uVar2 >> 8;
      eStack_48.cluster_id = (ind->addr_info).cluster_id;
      eStack_48.profile_id = (ind->addr_info).profile_id;
      eStack_48.lqi = ind->lqi;
      eStack_48.rssi = ind->rssi;
      eStack_48.asdu = puVar6;
      _Var5 = (*p_Var3)(&eStack_48);
      iVar4 = CONCAT31(extraout_var,_Var5);
      if (puVar6 != (uint8_t *)0x0) {
        mm_free(puVar6);
      }
      if (iVar4 == 0) {
_L0:
        iVar4 = 0;
      }
      else if (pzVar8 != (zmsg_t *)0x0) {
        zmsg_free(pzVar8);
      }
      return SUB41(iVar4,0);
    }
  }
  log_write(2,"aps_api.c",0x10000);
  iVar4 = 0;
  goto _L0;
}

