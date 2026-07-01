/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_and_unbindreq_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Removing unreachable block (ram,0x000104ee) */
/* WARNING: Removing unreachable block (ram,0x000104f8) */
/* WARNING: Removing unreachable block (ram,0x00010550) */
/* WARNING: Removing unreachable block (ram,0x000104de) */
/* WARNING: Removing unreachable block (ram,0x000104e8) */
/* WARNING: Removing unreachable block (ram,0x000105bc) */
/* WARNING: Removing unreachable block (ram,0x0001052e) */
/* WARNING: Removing unreachable block (ram,0x000104fe) */
/* WARNING: Removing unreachable block (ram,0x00010562) */
/* WARNING: Removing unreachable block (ram,0x000105c2) */
/* WARNING: Removing unreachable block (ram,0x00010588) */
/* WARNING: Removing unreachable block (ram,0x00010590) */
/* WARNING: Removing unreachable block (ram,0x0001050a) */
/* WARNING: Removing unreachable block (ram,0x00010592) */
/* WARNING: Removing unreachable block (ram,0x00010512) */
/* WARNING: Removing unreachable block (ram,0x00010528) */
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
  dst_addr.u._6_1_ = 0;
  dst_addr._0_4_ = 0;
  dst_addr.u.group_addr.bcast = 0;
  if (packet == (zdo_packet_t *)0x0) {
    return 0xfe;
  }
  if (packet->payload == (zdo_packet_payload_t *)0x0) {
    return 0xfe;
  }
  if (resp == (zdo_packet_t *)0x0) {
    return 0xfe;
  }
  if (0xfff7 < packet->dst_addr) {
    return 0xfe;
  }
  zVar1 = zdo_op_bind_and_unbind_req(packet->payload,(zdp_bind_req_field_t *)&rsp,false);
  if (CONCAT31(extraout_var,zVar1) != 0) {
    return 0xfe;
  }
  iVar2 = nwk_get_extended_address();
  if (iVar2 != 0) {
    piVar3 = (int *)nwk_get_extended_address();
    if ((_rsp == *piVar3) && (piVar3[1] == 0)) {
      dst_addr.u._6_1_ = 0x82;
      goto _L0;
    }
  }
  dst_addr.u._6_1_ = 0x84;
_L0:
  zVar1 = zdo_op_bind_and_unbind_rsp
                    (resp->payload,(zdp_bind_rsp_field_t *)((int)&dst_addr.u + 6),true);
  return zVar1;
}

