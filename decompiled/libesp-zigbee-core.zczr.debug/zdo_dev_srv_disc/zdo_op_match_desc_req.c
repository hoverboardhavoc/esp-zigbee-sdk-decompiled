/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_match_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_match_desc_req(zdo_packet_payload_t *payload,zdp_match_desc_req_field_t *req,_Bool is_write)

{
  uint uVar1;
  zdp_status_t zVar2;
  int iVar3;
  uint uVar4;
  uint16_t *puVar5;
  undefined3 in_register_00002031;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_match_desc_req_field_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1f0,"zdo_op_match_desc_req"
                  ,"payload && req");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      auStack_22[0] = 0;
      uVar4 = zmsg_get_length();
      af_read_le16(payload,auStack_22,&req->nwk_addr_of_interest);
      af_read_le16(payload,auStack_22,&req->profile_id);
      af_read_le8(payload,auStack_22,&req->num_in_clusters);
      uVar1 = (uint)req->num_in_clusters;
      puVar5 = (uint16_t *)calloc(uVar1,2);
      req->cluster_list = puVar5;
      if (puVar5 == (uint16_t *)0x0) {
        if (uVar1 != 0) {
          return 0x8a;
        }
      }
      else {
        uVar1 = 0;
      }
      for (; uVar1 < req->num_in_clusters; uVar1 = uVar1 + 1 & 0xff) {
        af_read_le16(payload,auStack_22,req->cluster_list + uVar1);
      }
      af_read_le8(payload,auStack_22,&req->num_out_clusters);
      puVar5 = (uint16_t *)
               mm_realloc(req->cluster_list,(uint)req->num_in_clusters + (uint)req->num_out_clusters
                          ,2);
      req->cluster_list = puVar5;
      if ((puVar5 == (uint16_t *)0x0) &&
         ((uint)req->num_in_clusters + (uint)req->num_out_clusters != 0)) {
        return 0x8a;
      }
      for (uVar1 = (uint)req->num_in_clusters;
          uVar1 < (uint)req->num_in_clusters + (uint)req->num_out_clusters; uVar1 = uVar1 + 1 & 0xff
          ) {
        af_read_le16(payload,auStack_22,req->cluster_list + uVar1);
      }
      if (auStack_22[0] <= uVar4) {
        return '\0';
      }
      return 0xfe;
    }
    auStack_22[0] = req->nwk_addr_of_interest;
    iVar3 = zmsg_append_bytes(2,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = req->profile_id;
    iVar3 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->num_in_clusters);
    iVar3 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    for (uVar1 = 0; uVar1 < req->num_in_clusters; uVar1 = uVar1 + 1 & 0xff) {
      auStack_22[0] = req->cluster_list[uVar1];
      iVar3 = zmsg_append_bytes(payload,2,auStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
    }
  }
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->num_out_clusters);
  iVar3 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar3 == 0) {
    for (uVar1 = 0; uVar1 < req->num_out_clusters; uVar1 = uVar1 + 1 & 0xff) {
      auStack_22[0] = req->cluster_list[req->num_in_clusters + uVar1];
      iVar3 = zmsg_append_bytes(payload,2,auStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
    }
    zVar2 = '\0';
  }
  else {
    zVar2 = 0x8a;
  }
  return zVar2;
}

