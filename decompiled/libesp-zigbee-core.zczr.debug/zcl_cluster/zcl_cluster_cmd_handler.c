/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_cluster_cmd_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  uint16_t cluster_id;
  zcl_cluster_template_t *template;
  uint8_t cluster_role;
  
  if (packet == (zcl_packet_t *)0x0) {
    cluster_id = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_cluster.c",0x91,
                               "zcl_cluster_cmd_handler","packet");
  }
  else {
    cluster_id = (packet->header).cluster_id;
    if (((packet->header).fc & 8) != 0) {
      cluster_role = '\x02';
      goto _L0;
    }
  }
  cluster_role = '\x01';
_L0:
  template = zcl_cluster_template_find(cluster_id,cluster_role);
  if (template == (zcl_cluster_template_t *)0x0) {
    zVar1 = 0x81;
  }
  else if ((short)(packet->header).cluster_id < 0) {
    zVar1 = zcl_cluster_custom_cmd_handler(packet,template);
  }
  else if ((template->field_5).cmd_proc_handler == (zcl_cluster_process_cmd_t)0x0) {
    zVar1 = 0x81;
  }
  else {
    zVar1 = (*(template->field_5).cmd_proc_handler)(packet);
  }
  return zVar1;
}

