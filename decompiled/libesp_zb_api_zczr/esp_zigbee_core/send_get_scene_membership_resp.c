/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> send_get_scene_membership_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void send_get_scene_membership_resp(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  iVar1 = zb_aps_is_endpoint_in_group(DAT_00018f08,DAT_00018ed8);
  if (iVar1 == 0) {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00018ee1;
    puVar2[2] = 6;
    puVar2[3] = 0x85;
    puVar2[4] = 0xff;
    pcVar3 = (char *)zb_put_next_htole16(puVar2 + 5,DAT_00018f08);
  }
  else {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00018ee1;
    puVar2[2] = 6;
    puVar2[3] = 0;
    puVar2[4] = 0;
    pcVar4 = (char *)zb_put_next_htole16(puVar2 + 5,DAT_00018f08);
    *pcVar4 = '\0';
    pcVar3 = pcVar4 + 1;
    for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1 & 0xff) {
      if (((&esp_zb_zcl_scenes_table)[uVar5 * 0xc] == DAT_00018ed8) &&
         ((&DAT_00018f0e)[uVar5 * 6] == DAT_00018f08)) {
        *pcVar4 = *pcVar4 + '\x01';
        *pcVar3 = (&DAT_00018f12)[uVar5 * 0xc];
        pcVar3 = pcVar3 + 1;
      }
      else if ((&DAT_00018f0e)[uVar5 * 6] == -1) {
        puVar2[4] = puVar2[4] + '\x01';
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,pcVar3,&scene_resp_info,2,DAT_00018ed7,DAT_00018ed8,DAT_00018edc >> 8 & 0xffff,
             5);
  return;
}

