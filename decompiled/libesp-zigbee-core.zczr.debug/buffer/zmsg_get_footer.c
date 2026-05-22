/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_get_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void zmsg_get_footer(zmsg_t *msg,void *obj,uint16_t len)

{
  ushort uVar1;
  buffer_t *pbVar2;
  uint8_t *puVar3;
  int iVar4;
  void *__src;
  undefined2 in_register_00002032;
  char *__n;
  
  uVar1 = msg->tail;
  if (CONCAT22(in_register_00002032,len) <= (uint)uVar1) {
    pbVar2 = buffers_get_last(msg->chunks);
    puVar3 = buffer_get_tail(pbVar2,uVar1);
    memcpy(obj,puVar3,CONCAT22(in_register_00002032,len));
    return;
  }
  __n = "zmsg_get_footer";
  iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x180,
                        "len <= msg->tail");
  uVar1 = *(ushort *)(iVar4 + 0x10);
  if (__n <= (char *)(uint)uVar1) {
    pbVar2 = buffers_get_last(*(buffer_t **)(iVar4 + 8));
    puVar3 = buffer_get_tail(pbVar2,uVar1);
    memcpy(puVar3,__src,(size_t)__n);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x188,
                "len <= msg->tail");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

