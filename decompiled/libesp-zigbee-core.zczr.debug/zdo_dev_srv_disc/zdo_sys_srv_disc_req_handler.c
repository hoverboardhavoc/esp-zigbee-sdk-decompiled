/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_sys_srv_disc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_sys_srv_disc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  int iVar2;
  zdp_sys_srv_disc_rsp_field_t zStack_18;
  zdp_sys_srv_disc_rsp_field_t rsp;
  zdp_sys_srv_disc_req_field_t req;
  
  rsp.status = '\0';
  rsp._1_1_ = 0;
  zStack_18.status = '\0';
  zStack_18.server_mask = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_sys_srv_disc_req(packet->payload,(zdp_sys_srv_disc_req_field_t *)&rsp,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      iVar2 = af_get_node_desc();
      if (iVar2 == 0) {
        zVar1 = '\0';
      }
      else {
        zStack_18.server_mask = *(ushort *)(iVar2 + 10) & rsp._0_2_ & 0x1ff;
        if (*(ushort *)(iVar2 + 10) >> 9 == (ushort)rsp._0_2_ >> 9) {
          zStack_18.server_mask = zStack_18.server_mask | rsp._0_2_ & 0xfe00;
        }
        if (zStack_18.server_mask == 0) {
          zVar1 = 0xfe;
        }
        else {
          zVar1 = zdo_op_sys_srv_disc_rsp(resp->payload,&zStack_18,true);
        }
      }
    }
    else {
      zVar1 = 0xfe;
    }
  }
  return zVar1;
}

