/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_id_map_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: zone_id_map */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_get_zone_id_map_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_a4;
  byte *pbVar4;
  int iVar5;
  uint16_t uStack_32;
  ushort local_30 [2];
  uint16_t zone_id_map [16];
  
  local_30[0] = 0;
  local_30[1] = 0;
  zone_id_map[0] = 0;
  zone_id_map[1] = 0;
  zone_id_map[2] = 0;
  zone_id_map[3] = 0;
  zone_id_map[4] = 0;
  zone_id_map[5] = 0;
  zone_id_map[6] = 0;
  zone_id_map[7] = 0;
  zone_id_map[8] = 0;
  zone_id_map[9] = 0;
  zone_id_map[10] = 0;
  zone_id_map[0xb] = 0;
  zone_id_map[0xc] = 0;
  zone_id_map[0xd] = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x14c,
                  "ias_ace_cluster_get_zone_id_map_cmd_handler","packet && rsp");
  }
  else {
    piVar2 = (int *)ezb_zcl_ias_ace_get_zone_table((packet->header).dst_ep);
    if (piVar2 != (int *)0x0) {
      in_a4 = 0;
      goto _L0;
    }
  }
  piVar2 = (int *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c"
                                ,0x14e,"ias_ace_cluster_get_zone_id_map_cmd_handler","table");
  while( true ) {
    in_a4 = in_a4 + 1;
_L0:
    if ((int)(uint)*(byte *)(piVar2 + 1) <= in_a4) break;
    pbVar4 = (byte *)(in_a4 * 0x1e + *piVar2);
    if (*(short *)(pbVar4 + 2) != -1) {
      bVar1 = *pbVar4;
      zone_id_map[(bVar1 >> 4) - 2] = (ushort)(1 << (bVar1 & 0xf)) | zone_id_map[(bVar1 >> 4) - 2];
    }
  }
  iVar5 = 0;
  do {
    if (0xf < iVar5) {
      iVar5 = zcl_packet_setup_response(rsp,packet,1);
      if (iVar5 != 0) {
_L0:
        iVar5 = zcl_packet_setup_default_response(rsp,packet,iVar5);
      }
      return (ezb_zcl_status_t)iVar5;
    }
    uStack_32 = zone_id_map[iVar5 + -2];
    iVar3 = zmsg_append_bytes(rsp->payload,2,&uStack_32);
    if (iVar3 != 0) {
      iVar5 = 0x89;
      goto _L0;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

