/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_platform.o -> esp_zb_platform_config
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_platform_config(uint *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  if (*param_1 < 2) {
    if (param_1[0xc] == 0) {
      puVar6 = &s_zb_platform_config;
      puVar1 = param_1 + 0x18;
      do {
        uVar3 = param_1[1];
        uVar4 = param_1[2];
        uVar5 = param_1[3];
        *puVar6 = *param_1;
        puVar6[1] = uVar3;
        puVar6[2] = uVar4;
        puVar6[3] = uVar5;
        param_1 = param_1 + 4;
        puVar6 = puVar6 + 4;
      } while (param_1 != puVar1);
      uVar2 = 0;
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): host mode uart not supported\n",uVar2,0x10000,
              "esp_zb_platform_config",0x37);
      uVar2 = 0x102;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Radio mode uart not supported\n",uVar2,0x10000,
            "esp_zb_platform_config",0x33);
    uVar2 = 0x102;
  }
  return uVar2;
}

