/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  iVar4 = __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x180,"len <= msg->tail");
  uVar1 = *(ushort *)(iVar4 + 0x10);
  if (__n <= (char *)(uint)uVar1) {
    pbVar2 = buffers_get_last(*(buffer_t **)(iVar4 + 8));
    puVar3 = buffer_get_tail(pbVar2,uVar1);
    memcpy(puVar3,__src,(size_t)__n);
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x188,"len <= msg->tail");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

