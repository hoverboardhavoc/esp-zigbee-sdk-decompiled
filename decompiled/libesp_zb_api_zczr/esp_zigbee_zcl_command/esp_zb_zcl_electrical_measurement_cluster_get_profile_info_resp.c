/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_electrical_measurement_cluster_get_profile_info_resp(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  undefined2 uVar9;
  
  uVar9 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar9 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar8 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar8;
    *pbVar8 = bVar2 + 1;
    return bVar2;
  }
  puVar5 = (undefined1 *)zb_buf_reuse_func();
  *puVar5 = 0x19;
  pcVar6 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar6;
  *pcVar6 = cVar1 + '\x01';
  puVar5[1] = cVar1;
  puVar5[2] = 0;
  puVar7 = puVar5 + 6;
  puVar5[3] = *(undefined1 *)(param_1 + 0x10);
  puVar5[4] = (char)*(undefined4 *)(param_1 + 0x14);
  puVar5[5] = *(undefined1 *)(param_1 + 0x18);
  if ((*(short *)(param_1 + 0x1a) != 0) && (iVar3 = 0, *(int *)(param_1 + 0x1c) != 0)) {
    for (; iVar3 < (int)(uint)*(ushort *)(param_1 + 0x1a); iVar3 = iVar3 + 1) {
      puVar7 = (undefined1 *)
               zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar3 * 2));
    }
  }
  zb_zcl_finish_and_send_packet
            (iVar4,puVar7,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar9,*(undefined2 *)(param_1 + 0x20));
  pbVar8 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar8 >> 2 & 1) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar8[iVar4];
}

