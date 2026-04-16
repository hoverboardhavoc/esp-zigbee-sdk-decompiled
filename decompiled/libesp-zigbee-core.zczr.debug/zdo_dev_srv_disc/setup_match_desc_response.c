/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> setup_match_desc_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
setup_match_desc_response
          (zdo_packet_payload_t *payload,zdp_match_desc_rsp_field_t *rsp,
          zdp_match_desc_req_field_t *req)

{
  uint8_t uVar1;
  zdp_status_t zVar2;
  ushort uVar3;
  undefined3 extraout_var;
  ezb_zdp_status_t eVar4;
  uint16_t *out_clusters;
  uint16_t *in_clusters;
  uint8_t auStack_60 [64];
  
  if (((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_match_desc_rsp_field_t *)0x0)) ||
     (req == (zdp_match_desc_req_field_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x408,
                  "setup_match_desc_response","payload && rsp && req");
  }
  else {
    uVar3 = req->nwk_addr_of_interest;
    if (uVar3 < 0xfff8) goto _L0;
  }
  uVar3 = nwk_get_short_address();
_L0:
  rsp->nwk_addr_of_interest = uVar3;
  if (rsp->status == '\0') {
    if (req->num_in_clusters == 0) {
      in_clusters = (uint16_t *)0x0;
    }
    else {
      in_clusters = req->cluster_list;
    }
    if (req->num_out_clusters == '\0') {
      out_clusters = (uint16_t *)0x0;
    }
    else {
      out_clusters = req->cluster_list + req->num_in_clusters;
    }
    memset(auStack_60,0,0x40);
    rsp->match_list = auStack_60;
    uVar1 = match_simple_desc(req->profile_id,in_clusters,req->num_in_clusters,out_clusters,
                              req->num_out_clusters,auStack_60);
    eVar4 = '\0';
    if (req->nwk_addr_of_interest < 0xfff8) {
      if (CONCAT31(extraout_var,uVar1) == 0) {
        eVar4 = 0x89;
      }
    }
    else if (CONCAT31(extraout_var,uVar1) == 0) {
      return 0xfe;
    }
    rsp->status = eVar4;
    rsp->match_length = uVar1;
    zVar2 = zdo_op_match_desc_rsp(payload,rsp,true);
  }
  else {
    rsp->match_length = '\0';
    zVar2 = zdo_op_match_desc_rsp(payload,rsp,true);
  }
  return zVar2;
}

