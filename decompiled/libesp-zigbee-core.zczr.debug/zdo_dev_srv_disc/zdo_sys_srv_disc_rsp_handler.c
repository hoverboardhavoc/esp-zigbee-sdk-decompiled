/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_sys_srv_disc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_sys_srv_disc_rsp_handler(zdo_packet_t *packet)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  int iVar2;
  zdp_sys_srv_disc_rsp_field_t zStack_14;
  zdp_sys_srv_disc_rsp_field_t rsp;
  
  zStack_14.status = '\0';
  zStack_14._1_1_ = 0;
  zStack_14.server_mask = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_sys_srv_disc_rsp(packet->payload,&zStack_14,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      if (((uint)zStack_14 & 0x400000) != 0) {
        iVar2 = core_globals_get();
        *(uint16_t *)(iVar2 + 0x9dc) = packet->src_addr;
      }
      zVar1 = zdo_cb_sys_srv_disc_rsp(&zStack_14,&packet->ctx);
    }
    else {
      zVar1 = 0xfe;
    }
  }
  return zVar1;
}

