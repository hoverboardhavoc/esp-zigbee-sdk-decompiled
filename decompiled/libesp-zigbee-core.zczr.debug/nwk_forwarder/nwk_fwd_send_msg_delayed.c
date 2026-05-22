/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_send_msg_delayed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_send_msg_delayed(zmsg_t *msg,uint32_t delay_ms)

{
  int iVar1;
  ushort uStack_14;
  ushort auStack_12 [2];
  uint16_t fcf;
  
  zmsg_read_bytes(0,2,auStack_12);
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xa28) != '\0') {
      auStack_12[0] = auStack_12[0] | 0x2000;
    }
  }
  else {
    auStack_12[0] = auStack_12[0] & 0xdfff;
  }
  uStack_14 = auStack_12[0];
  zmsg_write_bytes(msg,0,2,&uStack_14);
  msg->nwk_retries = '\0';
  nwk_fwd_retry(msg,delay_ms);
  return;
}

