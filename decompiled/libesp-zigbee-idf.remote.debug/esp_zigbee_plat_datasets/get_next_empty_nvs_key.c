/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> get_next_empty_nvs_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int get_next_empty_nvs_key(int param_1,char *param_2,size_t param_3)

{
  bool bVar1;
  int unaff_s0;
  int iVar2;
  char unaff_s2;
  undefined4 uStack_48;
  undefined1 auStack_44 [16];
  char acStack_34 [20];
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x32,"get_next_empty_nvs_key",0x10000);
    goto _L0;
  }
  unaff_s2 = '\0';
  unaff_s0 = 0x105;
_L0:
  if (unaff_s2 == -1) {
    return unaff_s0;
  }
  uStack_48 = 0;
  s_unused_pos_1 = s_unused_pos_1 + '\x01';
  snprintf(param_2,param_3,"ZB%02x%02x");
  unaff_s0 = nvs_entry_find_in_handle(param_1,0x42,&uStack_48);
  while (unaff_s0 == 0) {
    nvs_entry_info(uStack_48,auStack_44);
    iVar2 = strncmp(param_2,acStack_34,7);
    if (iVar2 == 0) goto _L0;
    unaff_s0 = nvs_entry_next(&uStack_48);
  }
  bVar1 = false;
  goto _L0;
_L0:
  bVar1 = true;
_L0:
  nvs_release_iterator(uStack_48);
  if (!bVar1) {
    return 0;
  }
  unaff_s2 = unaff_s2 + '\x01';
  goto _L0;
}

