/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_retrans_send_msg(ezb_shortaddr_t dst_addr,uint8_t blk_sz,aps_apsde_data_req_t *req)

{
  int iVar1;
  int iVar2;
  zmsg_t *pzVar3;
  uint8_t uStack_23;
  ezb_shortaddr_t aeStack_22 [7];
  
  uStack_23 = blk_sz;
  aeStack_22[0] = dst_addr;
  iVar1 = core_globals_get();
  pzVar3 = req->asdu;
  iVar2 = zmsg_add_footer(pzVar3,&uStack_23,1);
  if ((iVar2 == 0) && (iVar2 = zmsg_add_footer(pzVar3,aeStack_22,2), iVar2 == 0)) {
    zmsg_queue_enqueue(iVar1 + 0x48,pzVar3);
    tasklet_post(iVar1 + 0x38);
  }
  return iVar2;
}

