/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_id_map_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_zone_id_map_cmd_handler(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  ushort uStack_32;
  ushort local_30 [16];
  
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  local_30[8] = 0;
  local_30[9] = 0;
  local_30[10] = 0;
  local_30[0xb] = 0;
  local_30[0xc] = 0;
  local_30[0xd] = 0;
  local_30[0xe] = 0;
  local_30[0xf] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x14c,
                  "ias_ace_cluster_get_zone_id_map_cmd_handler","packet && rsp");
  }
  else {
    piVar2 = (int *)ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
    if (piVar2 != (int *)0x0) {
      param_3 = 0;
      goto _L0;
    }
  }
  piVar2 = (int *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c"
                                ,0x14e,"ias_ace_cluster_get_zone_id_map_cmd_handler","table");
  while( true ) {
    param_3 = param_3 + 1;
_L0:
    if ((int)(uint)*(byte *)(piVar2 + 1) <= param_3) break;
    pbVar4 = (byte *)(param_3 * 0x1e + *piVar2);
    if (*(short *)(pbVar4 + 2) != -1) {
      bVar1 = *pbVar4;
      local_30[bVar1 >> 4] = (ushort)(1 << (bVar1 & 0xf)) | local_30[bVar1 >> 4];
    }
  }
  iVar5 = 0;
  do {
    if (0xf < iVar5) {
      iVar5 = zcl_packet_setup_response(param_2,param_1,1);
      if (iVar5 != 0) {
_L0:
        zcl_packet_setup_default_response(param_2,param_1,iVar5);
      }
      return;
    }
    uStack_32 = local_30[iVar5];
    iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_32);
    if (iVar3 != 0) {
      iVar5 = 0x89;
      goto _L0;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

