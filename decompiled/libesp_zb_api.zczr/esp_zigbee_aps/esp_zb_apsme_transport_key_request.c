/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_aps.o -> esp_zb_apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_transport_key_request(void *param_1)

{
  char cVar1;
  int iVar2;
  void *__dest;
  void *__dest_00;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    return 0x101;
  }
  __dest = (void *)zb_buf_get_tail_func(0x28);
  memcpy(__dest,param_1,8);
  cVar1 = *(char *)((int)param_1 + 8);
  *(undefined1 *)((int)__dest + 8) = 3;
  *(char *)((int)__dest + 9) = cVar1;
  if (cVar1 == '\x01') {
    *(undefined1 *)((int)__dest + 0x1b) = *(undefined1 *)((int)param_1 + 0x22);
    __dest_00 = (void *)((int)__dest + 0x1c);
    *(undefined1 *)((int)__dest + 0x1a) = *(undefined1 *)((int)param_1 + 0x21);
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 != '\x04') {
        zb_buf_free_func(iVar2);
        return 0x106;
      }
      goto _L0;
    }
    *(undefined1 *)((int)__dest + 0x22) = *(undefined1 *)((int)param_1 + 0x21);
    __dest_00 = (void *)((int)__dest + 0x1a);
  }
  memcpy(__dest_00,(void *)((int)param_1 + 0x19),8);
_L0:
  memcpy((void *)((int)__dest + 10),(void *)((int)param_1 + 9),0x10);
  zb_schedule_callback(&zb_apsme_transport_key_request,iVar2);
  return 0;
}

