/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_add_cnf_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_err_t af_data_add_cnf_cb(zmsg_t *msg,af_user_cnf_ctx_t cnf_ctx)

{
  zmsg_t *pzVar1;
  int iVar2;
  zmsg_t *pzVar3;
  dlist_node_s *in_a1;
  buffer_t *in_a2;
  undefined4 uVar4;
  af_user_cnf_ctx_t cnf_ctx_local;
  
  pzVar3 = msg;
  if ((in_a1 != (dlist_node_s *)0x0) &&
     (pzVar1 = (zmsg_t *)calloc(1,0x10), pzVar3 = pzVar1, pzVar1 != (zmsg_t *)0x0)) {
    (pzVar1->node).next = &msg->node;
    (pzVar1->node).prev = in_a1;
    *(uint16_t **)&pzVar1->header = &pzVar1->header;
    pzVar1->chunks = in_a2;
    iVar2 = core_globals_get();
    pzVar3 = (zmsg_t *)(iVar2 + 0x1000);
    uVar4 = *(undefined4 *)(iVar2 + 0xd08);
    pzVar1->header = (short)uVar4;
    pzVar1->length = (short)((uint)uVar4 >> 0x10);
    *(uint16_t **)(iVar2 + 0xd08) = &pzVar1->header;
  }
  return (ezb_err_t)pzVar3;
}

