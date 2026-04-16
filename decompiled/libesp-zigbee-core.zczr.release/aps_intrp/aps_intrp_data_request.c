/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> aps_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_intrp_data_request(aps_intrp_data_req_t *req)

{
  ezb_shortaddr_t eVar1;
  uint16_t uVar2;
  undefined4 uVar3;
  void *__src;
  ezb_err_t eVar4;
  undefined1 *puVar5;
  uint in_a4;
  byte bVar6;
  undefined4 uStack_2c;
  nwk_intrp_data_req_t nwk_req;
  
  uStack_2c = 0;
  nwk_req.src_addr.addr_mode = '\0';
  nwk_req.src_addr._1_1_ = 0;
  nwk_req.src_addr.u.short_addr._0_1_ = 0;
  if (req->asdu == (zmsg_t *)0x0) {
    __assert_func(0,0,0,0);
  }
  else {
    in_a4 = (uint)(req->dst_addr).addr_mode;
    bVar6 = 0xf;
    if (in_a4 == 1) goto _L0;
  }
  bVar6 = 3;
  if (in_a4 == 2) {
    bVar6 = (0xfff7 < (req->dst_addr).u.short_addr) * '\b' + 3;
  }
_L0:
  uVar3 = uStack_2c;
  uStack_2c = CONCAT31(uStack_2c._1_3_,bVar6);
  puVar5 = (undefined1 *)((int)&uStack_2c + 1);
  if ((bVar6 & 0xc) == 0xc) {
    eVar1 = (req->dst_addr).u.short_addr;
    puVar5 = (undefined1 *)((int)&uStack_2c + 3);
    uStack_2c._3_1_ = SUB41(uVar3,3);
    uStack_2c._0_3_ = CONCAT12((char)(eVar1 >> 8),CONCAT11((char)eVar1,bVar6));
  }
  uVar2 = req->cluster_id;
  *puVar5 = (char)uVar2;
  puVar5[1] = (char)(uVar2 >> 8);
  uVar2 = req->profile_id;
  puVar5[2] = (char)uVar2;
  puVar5[3] = (char)(uVar2 >> 8);
  zmsg_prepend_bytes((uint)(puVar5 + (4 - (int)&uStack_2c)) & 0xffff,&uStack_2c);
  uStack_2c = CONCAT31(uStack_2c._1_3_,3);
  __src = (void *)nwk_get_extended_address();
  memcpy((void *)((int)&uStack_2c + 2),__src,8);
  nwk_req.src_addr.u._4_2_ = req->dst_pan_id;
  memcpy((void *)((int)&nwk_req.src_addr.u + 6),&req->dst_addr,10);
  nwk_req._20_4_ = req->asdu;
  if ((zmsg_t *)nwk_req._20_4_ != (zmsg_t *)0x0) {
    req->asdu = (zmsg_t *)0x0;
  }
  zmsg_add_footer(req,0x18);
  eVar4 = nwk_intrp_data_request(&uStack_2c);
  if (req->asdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return eVar4;
}

