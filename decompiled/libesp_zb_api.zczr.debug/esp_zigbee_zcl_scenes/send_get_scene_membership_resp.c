/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> send_get_scene_membership_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void send_get_scene_membership_resp(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  iVar1 = zb_aps_is_endpoint_in_group(_DAT_00012bf4,DAT_00012bc4);
  if (iVar1 == 0) {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00012bcd;
    puVar2[2] = 6;
    puVar2[3] = 0x85;
    puVar2[4] = 0xff;
    pcVar3 = (char *)zb_put_next_htole16(puVar2 + 5,_DAT_00012bf4);
  }
  else {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00012bcd;
    puVar2[2] = 6;
    puVar2[3] = 0;
    puVar2[4] = 0;
    pcVar4 = (char *)zb_put_next_htole16(puVar2 + 5,_DAT_00012bf4);
    *pcVar4 = '\0';
    pcVar3 = pcVar4 + 1;
    for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1 & 0xff) {
      if (((&esp_zb_zcl_scenes_table)[uVar5 * 0xc] == DAT_00012bc4) &&
         ((&DAT_00012bfa)[uVar5 * 6] == _DAT_00012bf4)) {
        *pcVar4 = *pcVar4 + '\x01';
        *pcVar3 = (&DAT_00012bfe)[uVar5 * 0xc];
        pcVar3 = pcVar3 + 1;
      }
      else if ((&DAT_00012bfa)[uVar5 * 6] == -1) {
        puVar2[4] = puVar2[4] + '\x01';
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,pcVar3,&scene_resp_info,2,DAT_00012bc3,DAT_00012bc4,DAT_00012bc8 >> 8 & 0xffff,
             5);
  return;
}

