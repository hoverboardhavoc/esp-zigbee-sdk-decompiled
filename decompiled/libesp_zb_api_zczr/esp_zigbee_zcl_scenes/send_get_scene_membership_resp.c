/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> send_get_scene_membership_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void send_get_scene_membership_resp(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar2 = zb_aps_is_endpoint_in_group(DAT_000115a4,DAT_00011574);
  if (iVar2 == 0) {
    puVar3 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar3 = 0x19;
    puVar3[1] = DAT_0001157d;
    puVar3[2] = 6;
    puVar3[3] = 0x85;
    puVar3[4] = 0xff;
    pcVar4 = (char *)zb_put_next_htole16(DAT_000115a4);
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar3 = 0x19;
    uVar1 = DAT_0001157d;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[1] = uVar1;
    puVar3[2] = 6;
    pcVar5 = (char *)zb_put_next_htole16(puVar3 + 5,DAT_000115a4);
    pcVar6 = &esp_zb_zcl_scenes_table;
    *pcVar5 = '\0';
    pcVar4 = pcVar5 + 1;
    do {
      if ((*pcVar6 == DAT_00011574) && (DAT_000115a4 == *(short *)(pcVar6 + 2))) {
        *pcVar5 = *pcVar5 + '\x01';
        *pcVar4 = pcVar6[6];
        pcVar4 = pcVar4 + 1;
      }
      else if (*(short *)(pcVar6 + 2) == -1) {
        puVar3[4] = puVar3[4] + '\x01';
      }
      pcVar6 = pcVar6 + 0xc;
    } while (pcVar6 != (char *)0x11668);
  }
  zb_zcl_finish_and_send_packet
            (param_1,pcVar4,&scene_resp_info,2,DAT_00011573,DAT_00011574,DAT_00011578 >> 8 & 0xffff,
             5);
  return;
}

