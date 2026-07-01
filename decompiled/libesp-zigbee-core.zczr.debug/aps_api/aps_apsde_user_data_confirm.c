/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> aps_apsde_user_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_apsde_user_data_confirm(aps_apsde_data_cnf_t *cnf)

{
  int unaff_s1;
  int iVar1;
  uint8_t *unaff_s2;
  zmsg_t *unaff_s3;
  ezb_apsde_data_confirm_t eStack_38;
  
  if (cnf == (aps_apsde_data_cnf_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",99,
                  "aps_apsde_user_data_confirm","cnf != ((void *)0)");
_L0:
    if (unaff_s1 == 0) goto _L0;
    log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.confirm");
    unaff_s1 = 0;
  }
  else {
    unaff_s3 = cnf->asdu;
    if (s_apsde_data_confirm_handler == (ezb_apsde_data_confirm_callback_t)0x0) goto _L0;
    unaff_s1 = zmsg_get_length(unaff_s3);
    unaff_s2 = (uint8_t *)mm_alloc_notrap(1,unaff_s1);
    if (unaff_s2 == (uint8_t *)0x0) goto _L0;
_L0:
    iVar1 = zmsg_read_bytes(unaff_s3,0,unaff_s1,unaff_s2);
    if (iVar1 != unaff_s1) {
      s_apsde_data_ind_handler =
           (ezb_apsde_data_indication_callback_t)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x70,
                         "aps_apsde_user_data_confirm",
                         "asdu_length == zmsg_read_bytes(msg, 0, asdu_length, asdu)");
      return;
    }
  }
  eStack_38.dst_address._0_4_ = *(undefined4 *)&cnf->dst_addr;
  eStack_38.dst_address.u._2_4_ = *(undefined4 *)((int)&(cnf->dst_addr).u + 2);
  eStack_38.dst_address.u._6_2_ = *(undefined2 *)((int)&(cnf->dst_addr).u + 6);
  eStack_38.src_endpoint = cnf->src_ep;
  eStack_38.dst_endpoint = cnf->dst_ep;
  eStack_38.cluster_id = cnf->cluster_id;
  eStack_38.profile_id = cnf->profile_id;
  eStack_38.status = cnf->status;
  eStack_38.asdu_length = (uint16_t)unaff_s1;
  eStack_38.asdu = unaff_s2;
  (*s_apsde_data_confirm_handler)(&eStack_38);
  if (unaff_s2 != (uint8_t *)0x0) {
    mm_free(unaff_s2);
  }
_L0:
  if (unaff_s3 != (zmsg_t *)0x0) {
    zmsg_free(unaff_s3);
  }
  return;
}

