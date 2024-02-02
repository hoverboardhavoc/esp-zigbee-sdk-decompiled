/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
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
  
  iVar1 = zb_aps_is_endpoint_in_group(DAT_00017f70,DAT_00017f40);
  if (iVar1 == 0) {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00017f49;
    puVar2[2] = 6;
    puVar2[3] = 0x85;
    puVar2[4] = 0xff;
    pcVar3 = (char *)zb_put_next_htole16(puVar2 + 5,DAT_00017f70);
  }
  else {
    puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
    *puVar2 = 0x19;
    puVar2[1] = DAT_00017f49;
    puVar2[2] = 6;
    puVar2[3] = 0;
    puVar2[4] = 0;
    pcVar4 = (char *)zb_put_next_htole16(puVar2 + 5,DAT_00017f70);
    *pcVar4 = '\0';
    pcVar3 = pcVar4 + 1;
    for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1 & 0xff) {
      if (((&esp_zb_zcl_scenes_table)[uVar5 * 0xc] == DAT_00017f40) &&
         ((&DAT_00017f76)[uVar5 * 6] == DAT_00017f70)) {
        *pcVar4 = *pcVar4 + '\x01';
        *pcVar3 = (&DAT_00017f7a)[uVar5 * 0xc];
        pcVar3 = pcVar3 + 1;
      }
      else if ((&DAT_00017f76)[uVar5 * 6] == -1) {
        puVar2[4] = puVar2[4] + '\x01';
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,pcVar3,&scene_resp_info,2,DAT_00017f3f,DAT_00017f40,DAT_00017f44 >> 8 & 0xffff,
             5);
  return;
}

