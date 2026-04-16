/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_query_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_query_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  char cVar3;
  undefined3 extraout_var;
  int iVar4;
  zcl_attr_desc_t *pzVar5;
  undefined2 uStack_12;
  
  ep_id = (packet->header).dst_ep;
  if (rsp == (zcl_packet_t *)0x0) {
    cVar3 = -2;
    goto _L0;
  }
  _Var1 = ezb_zcl_is_identifying(ep_id);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    cVar3 = '\0';
  }
  else {
    pzVar5 = identify_srv_get_attr_desc(ep_id,0);
    if (pzVar5 == (zcl_attr_desc_t *)0x0) {
      cVar3 = -0x7a;
      goto _L0;
    }
    if ((undefined2 *)pzVar5->data_p == (undefined2 *)0x0) {
      cVar3 = -0x7a;
      goto _L0;
    }
                    /* WARNING: Load size is inaccurate */
    uStack_12 = *pzVar5->data_p;
    cVar3 = zmsg_append_bytes(rsp->payload,2,&uStack_12);
    if (cVar3 != '\0') goto _L0;
  }
  iVar4 = zmsg_get_length(rsp->payload);
  if (iVar4 != 0) {
    eVar2 = zcl_packet_setup_response(rsp,packet,0);
    return eVar2;
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,cVar3);
  return eVar2;
}

