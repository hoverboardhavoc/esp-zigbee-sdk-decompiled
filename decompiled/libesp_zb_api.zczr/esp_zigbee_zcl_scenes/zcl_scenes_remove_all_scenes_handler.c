/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_remove_all_scenes_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_all_scenes_handler(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  short *psVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  
  iVar6 = zb_buf_get_tail_func(0x38);
  psVar5 = *(short **)(iVar6 + 0x10);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  puVar8 = *(undefined1 **)(iVar6 + 0x14);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  cVar1 = *(char *)(*(int *)(iVar6 + 0xc) + 0xc);
  iVar6 = esp_zb_zcl_scenes_group_check(cVar1,*psVar5);
  *puVar8 = (char)iVar6;
  if (iVar6 == 0) {
    sVar2 = *psVar5;
    pcVar7 = &esp_zb_zcl_scenes_table;
    cVar4 = '\0';
    cVar3 = '\0';
    do {
      if ((*pcVar7 == cVar1) && (*(short *)(pcVar7 + 2) == sVar2)) {
        cVar3 = cVar3 + '\x01';
        device_scenes_table_record_free(cVar4);
      }
      cVar4 = cVar4 + '\x01';
      pcVar7 = pcVar7 + 0xc;
    } while (cVar4 != '\x10');
    puVar8[1] = cVar3;
  }
  iVar6 = zb_nvram_write_dataset(9);
  return -(uint)(iVar6 != 0);
}

