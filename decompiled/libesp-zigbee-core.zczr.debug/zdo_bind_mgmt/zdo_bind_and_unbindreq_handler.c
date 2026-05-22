/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_and_unbindreq_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000104be) */
/* WARNING: Removing unreachable block (ram,0x000104c8) */
/* WARNING: Removing unreachable block (ram,0x00010528) */
/* WARNING: Removing unreachable block (ram,0x000104ae) */
/* WARNING: Removing unreachable block (ram,0x000104b8) */
/* WARNING: Removing unreachable block (ram,0x000104ee) */
/* WARNING: Removing unreachable block (ram,0x00010506) */
/* WARNING: Removing unreachable block (ram,0x000104ce) */
/* WARNING: Removing unreachable block (ram,0x0001053a) */
/* WARNING: Removing unreachable block (ram,0x000104da) */
/* WARNING: Removing unreachable block (ram,0x000104e2) */
/* WARNING: Removing unreachable block (ram,0x0001055c) */
/* WARNING: Removing unreachable block (ram,0x00010582) */
/* WARNING: Removing unreachable block (ram,0x0001056c) */
/* WARNING: Removing unreachable block (ram,0x0001058c) */
/* WARNING: Removing unreachable block (ram,0x00010572) */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_bind_and_unbindreq_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  ezb_address_t dst_addr;
  zdp_bind_rsp_field_t rsp;
  zdp_bind_req_field_t req;
  
  _rsp = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->dst_addr < 0xfff8) {
    zVar1 = zdo_op_bind_and_unbind_req(packet->payload,(zdp_bind_req_field_t *)&rsp,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      iVar2 = nwk_get_extended_address();
      if (iVar2 != 0) {
        piVar3 = (int *)nwk_get_extended_address();
        if ((_rsp == *piVar3) && (piVar3[1] == 0)) {
          return 0x82;
        }
      }
      zVar1 = 0x84;
    }
    else {
      zVar1 = 0xfe;
    }
  }
  else {
    zVar1 = 0xfe;
  }
  return zVar1;
}

