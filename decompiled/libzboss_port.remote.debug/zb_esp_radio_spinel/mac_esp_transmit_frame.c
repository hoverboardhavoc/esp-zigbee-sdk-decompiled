/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> mac_esp_transmit_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_esp_transmit_frame(undefined4 param_1)

{
  size_t __n;
  void *__src;
  
  __n = zb_buf_len_func();
  __src = (void *)zb_buf_begin_func(param_1);
  s_tx_buf = (char)__n + '\x02';
  memcpy(&s_tx_buf,__src,__n);
  esp_radio_spinel_transmit(&s_tx_buf,s_channel,1,0);
  return;
}

