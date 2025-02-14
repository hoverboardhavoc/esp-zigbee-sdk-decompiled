/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_read_mac
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_read_mac(int param_1,uint param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if (param_1 != 0) {
    esp_radio_spinel_get_eui64(0);
    for (param_2 = 0; param_2 < 4; param_2 = param_2 + 1 & 0xff) {
_L0:
      uVar1 = *(undefined1 *)(param_1 + param_2);
      puVar2 = (undefined1 *)((7 - param_2) + param_1);
      *(undefined1 *)(param_1 + param_2) = *puVar2;
      *puVar2 = uVar1;
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_radio_spinel.c",
                0xee,"zb_read_mac","mac_addr");
  goto _L0;
}

