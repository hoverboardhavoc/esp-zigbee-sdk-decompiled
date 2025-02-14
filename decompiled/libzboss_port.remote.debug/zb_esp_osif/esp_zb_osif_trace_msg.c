/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> esp_zb_osif_trace_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_osif_trace_msg
               (undefined4 param_1,undefined4 param_2,char *param_3,char *param_4,undefined4 param_5
               ,__gnuc_va_list param_6)

{
  int iVar1;
  char *pcVar2;
  byte abStack_121 [265];
  
  iVar1 = zb_trace_check(param_2,param_1);
  if (iVar1 != 0) {
    memset(abStack_121 + 1,0,0x100);
    iVar1 = vsnprintf((char *)(abStack_121 + 1),0xff,param_3,param_6);
    while (((-1 < iVar1 + -1 && ((abStack_121[iVar1] - 10 & 0xff) < 0x17)) &&
           ((0x400009U >> (abStack_121[iVar1] - 10 & 0x1f) & 1) != 0))) {
      abStack_121[iVar1] = 0;
      iVar1 = iVar1 + -1;
    }
    if (abStack_121[1] != '\0') {
      pcVar2 = strstr(param_4,"/zboss/");
      if (pcVar2 != (char *)0x0) {
        param_4 = pcVar2 + 7;
      }
      esp_rom_printf("ZB_TRACE_LOG[%d]: %s:%d    %s\n",param_2,param_4,param_5,abStack_121 + 1);
    }
  }
  return;
}

