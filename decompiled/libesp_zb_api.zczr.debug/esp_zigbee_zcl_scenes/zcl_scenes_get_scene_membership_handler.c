/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1,char *param_2)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  psVar3 = *(short **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  if ((psVar3 == (short *)0x0) || (iVar4 == 0)) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_L0,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                  "zcl_scenes_get_scene_membership_handler",0x276);
    uVar9 = 0xffffffff;
  }
  else {
    iVar5 = zb_buf_get_out_func();
    if (iVar5 == 0) {
      uVar9 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC5,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                    "zcl_scenes_get_scene_membership_handler",0x278);
      uVar9 = 0xffffffff;
    }
    else {
      cVar1 = *(char *)(iVar4 + 0xc);
      sVar2 = *psVar3;
      uVar6 = esp_zb_zcl_scenes_group_check(cVar1,sVar2);
      puVar7 = (undefined1 *)zb_buf_reuse_func(iVar5);
      *puVar7 = 0x19;
      puVar7[1] = *(undefined1 *)(iVar4 + 0x15);
      puVar7[2] = 6;
      puVar7[3] = (char)uVar6;
      if (uVar6 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = (char *)0xff;
      }
      puVar7[4] = (char)pcVar11;
      pcVar8 = (char *)zb_put_next_htole16(puVar7 + 5,sVar2);
      if ((pcVar8 == (char *)0x0) || (puVar7 == (undefined1 *)0xfffffffc)) {
        pcVar10 = (char *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_scenes.c"
                                    ,0x287);
        goto _L0;
      }
      if (uVar6 == 0) {
        *pcVar8 = '\0';
        pcVar10 = pcVar8;
        pcVar8 = pcVar8 + 1;
        for (; uVar6 < esp_zb_zcl_scenes_table_capacity; uVar6 = uVar6 + 1 & 0xff) {
          pcVar11 = (char *)(uVar6 * 0xc + esp_zb_zcl_scenes_table);
          param_2 = pcVar8;
          if (*pcVar11 == cVar1) {
_L0:
            pcVar8 = param_2;
            if (*(short *)(pcVar11 + 2) != sVar2) goto _L0;
            *pcVar10 = *pcVar10 + '\x01';
            *param_2 = pcVar11[6];
            pcVar8 = param_2 + 1;
          }
          else {
_L0:
            if (*(short *)(pcVar11 + 2) == -1) {
              puVar7[4] = puVar7[4] + '\x01';
            }
          }
        }
      }
      zb_zcl_finish_and_send_packet
                (iVar5,pcVar8,iVar4 + 1,2,*(undefined1 *)(iVar4 + 0xb),*(undefined1 *)(iVar4 + 0xc),
                 *(undefined2 *)(iVar4 + 0x11),5);
      uVar9 = 0;
    }
  }
  return uVar9;
}

