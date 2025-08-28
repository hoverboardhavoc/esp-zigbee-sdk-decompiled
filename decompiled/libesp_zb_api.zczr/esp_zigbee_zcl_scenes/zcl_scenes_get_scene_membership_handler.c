/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  char cVar4;
  char cVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  
  iVar7 = zb_buf_get_tail_func(0x38);
  psVar6 = *(short **)(iVar7 + 0x10);
  iVar7 = zb_buf_get_tail_func(param_1,0x38);
  iVar7 = *(int *)(iVar7 + 0xc);
  if (((psVar6 == (short *)0x0) || (iVar7 == 0)) || (iVar9 = zb_buf_get_out_func(), iVar9 == 0)) {
    uVar8 = 0xffffffff;
  }
  else {
    sVar3 = *psVar6;
    cVar1 = *(char *)(iVar7 + 0xc);
    iVar10 = esp_zb_zcl_scenes_group_check(cVar1,sVar3);
    puVar11 = (undefined1 *)zb_buf_reuse_func(iVar9);
    *puVar11 = 0x19;
    uVar2 = *(undefined1 *)(iVar7 + 0x15);
    puVar11[3] = (char)iVar10;
    puVar11[1] = uVar2;
    puVar11[2] = 6;
    puVar11[4] = -(iVar10 != 0);
    pcVar12 = (char *)zb_put_next_htole16(puVar11 + 5,sVar3);
    pcVar14 = pcVar12;
    if (pcVar12 == (char *)0x0) {
      pcVar12 = (char *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_scenes.c"
                                  ,0x287);
    }
    pcVar13 = esp_zb_zcl_scenes_table;
    cVar4 = esp_zb_zcl_scenes_table_capacity;
    if (iVar10 == 0) {
      *pcVar12 = '\0';
      pcVar12 = pcVar12 + 1;
      for (cVar5 = '\0'; cVar4 != cVar5; cVar5 = cVar5 + '\x01') {
        if ((*pcVar13 == cVar1) && (*(short *)(pcVar13 + 2) == sVar3)) {
          *pcVar14 = *pcVar14 + '\x01';
          *pcVar12 = pcVar13[6];
          pcVar12 = pcVar12 + 1;
        }
        else if (*(short *)(pcVar13 + 2) == -1) {
          puVar11[4] = puVar11[4] + '\x01';
        }
        pcVar13 = pcVar13 + 0xc;
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar9,pcVar12,iVar7 + 1,2,*(undefined1 *)(iVar7 + 0xb),*(undefined1 *)(iVar7 + 0xc),
               *(undefined2 *)(iVar7 + 0x11),5);
    uVar8 = 0;
  }
  return uVar8;
}

