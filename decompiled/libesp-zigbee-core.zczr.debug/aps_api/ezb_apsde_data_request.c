/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> ezb_apsde_data_request
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
  
  if (req == (ezb_apsde_data_req_t *)0x0) {
    iVar2 = 2;
  }
  else if ((req->asdu == (uint8_t *)0x0) && (req->asdu_length != 0)) {
    iVar2 = 2;
  }
  else {
    iStack_2c = zmsg_alloc(0xc);
    if (iStack_2c == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = zmsg_append_bytes(req->asdu_length,req->asdu);
      if (iVar2 == 0) {
        data_req.asdu = *(zmsg_t **)&req->dst_address;
        data_req.dst_addr._0_4_ = *(undefined4 *)((int)&(req->dst_address).u + 2);
        data_req.dst_addr.u._2_4_ = *(undefined4 *)((int)&(req->dst_address).u + 6);
        data_req._12_4_ = *(undefined4 *)&req->cluster_id;
        data_req._16_4_ = *(undefined4 *)&req->radius;
        bVar1 = req->tx_options;
        data_req._20_4_ =
             (bVar1 >> 5 & 1) << 4 |
             bVar1 & 1 | (bVar1 >> 2 & 1) << 1 | (bVar1 >> 3 & 1) << 2 | (bVar1 >> 4 & 1) << 3 |
             0x20;
        iVar2 = aps_apsde_data_request(&iStack_2c);
      }
      else {
        zmsg_free(iStack_2c);
      }
    }
  }
  return iVar2;
}

