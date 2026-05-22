/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_filter_address_conflict_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_filter_address_conflict_status(zmsg_t *msg,void *ctx)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 uVar3;
  char local_11 [4];
  uint8_t cmd_id;
  
  local_11[0] = '\0';
  uVar3 = zmsg_get_offset();
  zmsg_read_bytes(msg,uVar3,1,local_11);
  uVar1 = 0;
  if (local_11[0] == '\x03') {
    sVar2 = zmsg_get_offset(msg);
    uVar1 = zmsg_compare_bytes(msg,sVar2 + 1,ctx,3);
  }
  return (_Bool)uVar1;
}

