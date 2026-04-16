/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: data_req */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_apsde_data_request(ezb_apsde_data_req_t *req)

{
  byte bVar1;
  int iVar2;
  int iStack_2c;
  aps_apsde_data_req_t data_req;
  
  iVar2 = 2;
  if (req != (ezb_apsde_data_req_t *)0x0) {
    if ((req->asdu == (uint8_t *)0x0) && (req->asdu_length != 0)) {
      return 2;
    }
    iStack_2c = zmsg_alloc(0xc);
    iVar2 = 1;
    if (iStack_2c != 0) {
      iVar2 = zmsg_append_bytes(req->asdu_length,req->asdu);
      if (iVar2 == 0) {
        data_req.radius = '\0';
        data_req.alias_seq_num = '\0';
        data_req.alias_src_addr = 0;
        memcpy(&data_req,req,10);
        data_req.dst_addr.u._4_1_ = req->src_endpoint;
        data_req.dst_addr.u._5_1_ = req->dst_endpoint;
        bVar1 = req->tx_options;
        data_req._12_4_ = *(undefined4 *)&req->cluster_id;
        data_req._16_4_ = *(undefined4 *)&req->radius;
        data_req.radius =
             bVar1 >> 1 & 2 | bVar1 & 1 | 0x20 | bVar1 >> 1 & 4 | bVar1 >> 1 & 8 | bVar1 >> 1 & 0x10
             | (byte)data_req._20_4_ & 0xc0;
        iVar2 = aps_apsde_data_request(&iStack_2c);
      }
      else {
        zmsg_free(iStack_2c);
      }
    }
  }
  return iVar2;
}

