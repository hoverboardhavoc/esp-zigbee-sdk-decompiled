/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_and_unbindreq_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000104ae) */
/* WARNING: Removing unreachable block (ram,0x000104b8) */
/* WARNING: Removing unreachable block (ram,0x00010518) */
/* WARNING: Removing unreachable block (ram,0x0001049e) */
/* WARNING: Removing unreachable block (ram,0x000104a8) */
/* WARNING: Removing unreachable block (ram,0x000104de) */
/* WARNING: Removing unreachable block (ram,0x000104f6) */
/* WARNING: Removing unreachable block (ram,0x000104be) */
/* WARNING: Removing unreachable block (ram,0x0001052a) */
/* WARNING: Removing unreachable block (ram,0x000104ca) */
/* WARNING: Removing unreachable block (ram,0x000104d2) */
/* WARNING: Removing unreachable block (ram,0x0001054c) */
/* WARNING: Removing unreachable block (ram,0x00010572) */
/* WARNING: Removing unreachable block (ram,0x0001055c) */
/* WARNING: Removing unreachable block (ram,0x0001057c) */
/* WARNING: Removing unreachable block (ram,0x00010562) */
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

