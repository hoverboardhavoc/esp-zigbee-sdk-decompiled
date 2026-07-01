/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> aps_apsde_user_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_apsde_user_data_indication(aps_apsde_data_ind_t *ind)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int unaff_s1;
  _Bool _Var5;
  int iVar6;
  undefined3 extraout_var;
  ezb_apsde_data_indication_callback_t in_a5;
  uint8_t *unaff_s2;
  zmsg_t *unaff_s3;
  ezb_apsde_data_ind_t eStack_48;
  
  if (ind == (aps_apsde_data_ind_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x35,
                  "aps_apsde_user_data_indication",0x10000);
_L0:
    if (unaff_s1 == 0) goto _L0;
    log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.indication");
    unaff_s1 = 0;
_L0:
    eStack_48.asdu_length = (uint16_t)unaff_s1;
    eStack_48.src_address._1_1_ = 0;
    eStack_48.src_address.u.group_addr.bcast = 0;
    uVar2 = eStack_48.src_address.u.group_addr.bcast;
    eStack_48.src_address.u.group_addr.bcast = 0;
    eStack_48.src_address.u._4_4_ = 0;
    eStack_48.status = '\0';
    eStack_48.security_status = '\0';
    uVar3 = eStack_48._26_2_;
    eStack_48.status = '\0';
    eStack_48.security_status = '\0';
    eStack_48.key_index = '\0';
    eStack_48.lqi = '\0';
    eStack_48.rssi = '\0';
    eStack_48._31_1_ = 0;
    eStack_48._34_2_ = 0;
    uVar4 = eStack_48._34_2_;
    eStack_48._34_2_ = 0;
    in_a5 = s_apsde_data_ind_handler;
    if ((ind->addr_info).grp_addr == 0) goto _L0;
    eStack_48.src_address._1_1_ = 0;
    eStack_48.dst_address.u.short_addr = (ind->addr_info).grp_addr;
    eStack_48.dst_address._0_2_ = 1;
    eStack_48.dst_address.u._4_2_ = 0;
    eStack_48.dst_address.u.group_addr.bcast = (ind->addr_info).dst_addr;
  }
  else {
    unaff_s3 = ind->asdu;
    if (s_apsde_data_ind_handler == (ezb_apsde_data_indication_callback_t)0x0) {
      iVar6 = 0;
      goto _L0;
    }
    in_a5 = s_apsde_data_ind_handler;
    unaff_s1 = zmsg_get_length(unaff_s3);
    unaff_s2 = (uint8_t *)mm_alloc_notrap(1,unaff_s1);
    if (unaff_s2 == (uint8_t *)0x0) goto _L0;
_L0:
    iVar6 = zmsg_read_bytes(unaff_s3,0,unaff_s1,unaff_s2);
    if (iVar6 == unaff_s1) goto _L0;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x43,
                  "aps_apsde_user_data_indication",
                  "asdu_length == zmsg_read_bytes(msg, 0, asdu_length, asdu)");
    uVar2 = eStack_48.src_address.u.group_addr.bcast;
    uVar3 = eStack_48._26_2_;
    uVar4 = eStack_48._34_2_;
_L0:
    eStack_48._34_2_ = uVar4;
    eStack_48._26_2_ = uVar3;
    eStack_48.src_address.u.group_addr.bcast = uVar2;
    eStack_48.asdu_length = (uint16_t)unaff_s1;
    eStack_48.dst_address.u._2_4_ = 0;
    eStack_48.dst_address.u.short_addr = (ind->addr_info).dst_addr;
    eStack_48.dst_address._0_2_ = 2;
  }
  uVar1 = eStack_48._28_4_;
  eStack_48._8_3_ = 0x20000;
  eStack_48.src_address.u.short_addr = (ind->addr_info).src_addr;
  eStack_48.src_endpoint = (ind->addr_info).src_ep;
  eStack_48.dst_endpoint = (ind->addr_info).dst_ep;
  eStack_48.cluster_id = (ind->addr_info).cluster_id;
  eStack_48.profile_id = (ind->addr_info).profile_id;
  eStack_48.lqi = ind->lqi;
  eStack_48._31_1_ = SUB41(uVar1,3);
  eStack_48.rssi = ind->rssi;
  eStack_48.asdu = unaff_s2;
  _Var5 = (*in_a5)(&eStack_48);
  iVar6 = CONCAT31(extraout_var,_Var5);
  if (unaff_s2 != (uint8_t *)0x0) {
    mm_free(unaff_s2);
  }
  if ((iVar6 != 0) && (unaff_s3 != (zmsg_t *)0x0)) {
    zmsg_free(unaff_s3);
  }
_L0:
  return SUB41(iVar6,0);
}

