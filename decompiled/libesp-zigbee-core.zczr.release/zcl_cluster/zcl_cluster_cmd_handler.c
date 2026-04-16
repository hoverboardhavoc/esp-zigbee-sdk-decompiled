/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_cluster_cmd_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  zcl_cluster_template_t *pzVar2;
  size_t __size;
  void *pvVar3;
  zcl_cluster_process_cmd_t UNRECOVERED_JUMPTABLE;
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)__assert_func(0,0,0);
  }
  pzVar2 = zcl_cluster_template_find
                     ((packet->header).cluster_id,(((packet->header).fc & 8) != 0) + '\x01');
  if (pzVar2 != (zcl_cluster_template_t *)0x0) {
    UNRECOVERED_JUMPTABLE = (pzVar2->field_5).cmd_proc_handler;
    if ((short)(packet->header).cluster_id < 0) {
      if (UNRECOVERED_JUMPTABLE == (zcl_cluster_process_cmd_t)0x0) {
        return 0x81;
      }
      __size = zmsg_get_length(packet->payload);
      pvVar3 = calloc(1,__size);
      if ((pvVar3 == (void *)0x0) && (__size != 0)) {
        return 0x89;
      }
      zmsg_read_bytes(packet->payload,0,__size,pvVar3);
      zVar1 = (*(pzVar2->field_5).cmd_proc_handler)(packet);
      mm_free(pvVar3);
      return zVar1;
    }
    if (UNRECOVERED_JUMPTABLE != (zcl_cluster_process_cmd_t)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      zVar1 = (*UNRECOVERED_JUMPTABLE)(packet);
      return zVar1;
    }
  }
  return 0x81;
}

