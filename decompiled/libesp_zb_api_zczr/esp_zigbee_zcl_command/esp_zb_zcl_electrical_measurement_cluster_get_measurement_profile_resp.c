/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_reuse_func();
  *puVar3 = 0x19;
  pcVar4 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  puVar3[1] = cVar1;
  puVar3[2] = 1;
  puVar3 = (undefined1 *)zb_put_next_htole32(puVar3 + 3,*(undefined4 *)(param_1 + 0x10));
  *puVar3 = (char)*(undefined4 *)(param_1 + 0x14);
  puVar3[1] = (char)*(undefined4 *)(param_1 + 0x18);
  puVar3[2] = *(undefined1 *)(param_1 + 0x1c);
  uVar5 = zb_put_next_htole16(puVar3 + 3,*(undefined1 *)(param_1 + 0x1d));
  for (iVar6 = 0; iVar6 < (int)(uint)*(byte *)(param_1 + 0x1c); iVar6 = iVar6 + 1) {
  }
  zb_zcl_finish_and_send_packet
            (uVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x24));
  zb_zcl_frame_get_sequence_number(uVar2);
  return;
}

