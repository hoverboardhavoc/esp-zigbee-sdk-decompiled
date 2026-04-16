/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> aps_apsde_user_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_apsde_user_data_confirm(aps_apsde_data_cnf_t *cnf)

{
  ezb_apsde_data_confirm_callback_t p_Var1;
  int iVar2;
  uint8_t *puVar3;
  int iVar4;
  zmsg_t *pzVar5;
  ezb_apsde_data_confirm_t eStack_38;
  
  if (cnf != (aps_apsde_data_cnf_t *)0x0) goto _L0;
  while( true ) {
    cnf = (aps_apsde_data_cnf_t *)__assert_func(0,0,0,0);
_L0:
    pzVar5 = cnf->asdu;
    if (s_apsde_data_confirm_handler == (ezb_apsde_data_confirm_callback_t)0x0) goto _L0;
    iVar2 = zmsg_get_length(pzVar5);
    puVar3 = (uint8_t *)mm_alloc_notrap(1,iVar2);
    if ((puVar3 == (uint8_t *)0x0) && (iVar2 != 0)) break;
    iVar4 = zmsg_read_bytes(pzVar5,0,iVar2,puVar3);
    if (iVar4 == iVar2) {
_L0:
      p_Var1 = s_apsde_data_confirm_handler;
      memcpy(&eStack_38,cnf,10);
      eStack_38.src_endpoint = cnf->src_ep;
      eStack_38.dst_endpoint = cnf->dst_ep;
      eStack_38.status = cnf->status;
      eStack_38.asdu_length = (uint16_t)iVar2;
      eStack_38.cluster_id = cnf->cluster_id;
      eStack_38.profile_id = cnf->profile_id;
      eStack_38.asdu = puVar3;
      (*p_Var1)(&eStack_38);
      if (puVar3 != (uint8_t *)0x0) {
        mm_free(puVar3);
      }
_L0:
      if (pzVar5 != (zmsg_t *)0x0) {
        zmsg_free(pzVar5);
      }
      return;
    }
  }
  log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.confirm");
  iVar2 = 0;
  goto _L0;
}

