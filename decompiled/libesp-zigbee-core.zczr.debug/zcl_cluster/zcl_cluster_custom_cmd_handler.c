/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_custom_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_cluster_custom_cmd_handler(zcl_packet_t *packet,zcl_cluster_template_t *template)

{
  zcl_status_t zVar1;
  uint8_t *unaff_s2;
  size_t unaff_s3;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_cluster.c",0x7e,
                  "zcl_cluster_custom_cmd_handler","packet");
  }
  else {
    if (template == (zcl_cluster_template_t *)0x0) {
      return 0x81;
    }
    if ((template->field_5).cmd_proc_handler == (zcl_cluster_process_cmd_t)0x0) {
      return 0x81;
    }
    unaff_s3 = zmsg_get_length(packet->payload);
    unaff_s2 = (uint8_t *)calloc(1,unaff_s3);
    auStack_22[0] = 0;
    if (unaff_s2 != (uint8_t *)0x0) goto _L0;
  }
  if (unaff_s3 != 0) {
    return 0x89;
  }
_L0:
  af_read_bytes(packet->payload,auStack_22,(uint16_t)unaff_s3,unaff_s2);
  zVar1 = (*(template->field_5).cmd_proc_handler)(packet);
  mm_free(unaff_s2);
  return zVar1;
}

