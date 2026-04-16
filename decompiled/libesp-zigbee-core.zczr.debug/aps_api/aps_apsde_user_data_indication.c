/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> aps_apsde_user_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_apsde_user_data_indication(aps_apsde_data_ind_t *ind)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int unaff_s1;
  _Bool _Var4;
  int iVar5;
  undefined3 extraout_var;
  ezb_apsde_data_indication_callback_t in_a5;
  uint8_t *unaff_s2;
  zmsg_t *unaff_s3;
  ezb_apsde_data_ind_t eStack_44;
  
  if (ind == (aps_apsde_data_ind_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/aps_api.c",0x35,"aps_apsde_user_data_indication",
                  0x10000);
_L0:
    if (unaff_s1 == 0) goto _L0;
    log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.indication");
    unaff_s1 = 0;
_L0:
    eStack_44.asdu_length = (uint16_t)unaff_s1;
    eStack_44.src_address._1_1_ = 0;
    eStack_44.src_address.u.group_addr.bcast = 0;
    uVar1 = eStack_44.src_address.u.group_addr.bcast;
    eStack_44.src_address.u.group_addr.bcast = 0;
    eStack_44.src_address.u._4_4_ = 0;
    eStack_44.status = '\0';
    eStack_44.security_status = '\0';
    uVar2 = eStack_44._26_2_;
    eStack_44.status = '\0';
    eStack_44.security_status = '\0';
    eStack_44.key_index = '\0';
    eStack_44.lqi = '\0';
    uVar3 = eStack_44._28_2_;
    eStack_44.key_index = '\0';
    eStack_44.lqi = '\0';
    in_a5 = s_apsde_data_ind_handler;
    if ((ind->addr_info).grp_addr == 0) goto _L0;
    eStack_44.src_address._1_1_ = 0;
    eStack_44.dst_address.u.short_addr = (ind->addr_info).grp_addr;
    eStack_44.dst_address._0_2_ = 1;
    eStack_44.dst_address.u._4_2_ = 0;
    eStack_44.dst_address.u.group_addr.bcast = (ind->addr_info).dst_addr;
  }
  else {
    unaff_s3 = ind->asdu;
    if (s_apsde_data_ind_handler == (ezb_apsde_data_indication_callback_t)0x0) {
      iVar5 = 0;
      goto _L0;
    }
    in_a5 = s_apsde_data_ind_handler;
    unaff_s1 = zmsg_get_length(unaff_s3);
    unaff_s2 = (uint8_t *)mm_alloc_notrap(1,unaff_s1);
    if (unaff_s2 == (uint8_t *)0x0) goto _L0;
_L0:
    iVar5 = zmsg_read_bytes(unaff_s3,0,unaff_s1,unaff_s2);
    if (iVar5 == unaff_s1) goto _L0;
    __assert_func("//build/esp-zigbee/src/core/api/aps_api.c",0x43,"aps_apsde_user_data_indication",
                  "asdu_length == zmsg_read_bytes(msg, 0, asdu_length, asdu)");
    uVar1 = eStack_44.src_address.u.group_addr.bcast;
    uVar2 = eStack_44._26_2_;
    uVar3 = eStack_44._28_2_;
_L0:
    eStack_44._28_2_ = uVar3;
    eStack_44._26_2_ = uVar2;
    eStack_44.src_address.u.group_addr.bcast = uVar1;
    eStack_44.asdu_length = (uint16_t)unaff_s1;
    eStack_44.dst_address.u._2_4_ = 0;
    eStack_44.dst_address.u.short_addr = (ind->addr_info).dst_addr;
    eStack_44.dst_address._0_2_ = 2;
  }
  eStack_44._8_3_ = 0x20000;
  eStack_44.src_address.u.short_addr = (ind->addr_info).src_addr;
  eStack_44.src_endpoint = (ind->addr_info).src_ep;
  eStack_44.dst_endpoint = (ind->addr_info).dst_ep;
  eStack_44.cluster_id = (ind->addr_info).cluster_id;
  eStack_44.profile_id = (ind->addr_info).profile_id;
  eStack_44.asdu = unaff_s2;
  _Var4 = (*in_a5)(&eStack_44);
  iVar5 = CONCAT31(extraout_var,_Var4);
  if (unaff_s2 != (uint8_t *)0x0) {
    mm_free(unaff_s2);
  }
  if ((iVar5 != 0) && (unaff_s3 != (zmsg_t *)0x0)) {
    zmsg_free(unaff_s3);
  }
_L0:
  return SUB41(iVar5,0);
}

